import dataclasses
import requests
import time
from requests.adapters import HTTPAdapter
from requests.packages.urllib3.util.retry import Retry
from typing import TextIO, Tuple, Union


CODEFORCE_API_BASE = 'https://codeforces.com/api/'


@dataclasses.dataclass
class Submission:
    origin: str
    author: str
    contest_id: int
    submission_id: int
    creation_time_seconds: int
    problem: str
    programming_language: str
    time_consumed_millis: int
    memory_consumed_bytes: int
    source_code: str = ''


class TimeoutHTTPAdapter(HTTPAdapter):
    def __init__(self, *args, **kwargs):
        if "timeout" in kwargs:
            self.timeout = kwargs["timeout"]
            del kwargs["timeout"]
        super().__init__(*args, **kwargs)

    def send(self, request, **kwargs):
        timeout = kwargs.get("timeout")
        if timeout is None:
            kwargs["timeout"] = self.timeout
        return super().send(request, **kwargs)


def init_process():
    global session
    session = requests.Session()
    session.mount('http://', TimeoutHTTPAdapter(timeout=30))
    session.mount('https://', TimeoutHTTPAdapter(timeout=30))


def codeforce_call(method: str, params: dict, return_json: bool, log_file: TextIO) -> Tuple[Union[dict, str, None], bool]:
    global session
    try:
        log_file.write(f'INFO: Accessing {CODEFORCE_API_BASE + method} with params {params}.\n')
        log_file.flush()
        r = session.get(CODEFORCE_API_BASE + method, params=params, allow_redirects=False)
    except requests.exceptions.RequestException as e:
        log_file.write(f'WARNING: {CODEFORCE_API_BASE + method} with params {params} failed with message "{e}".\n')
        log_file.flush()
        return None, False
    if r.status_code == 200:
        if return_json:
            try:
                data = r.json()
            except:
                log_file.write(f'WARNING: {CODEFORCE_API_BASE + method} with params {params} failed to returned json.\n')
                log_file.flush()
                return None, False
            if data['status'] == 'OK':
                return data['result'], True
            else:
                log_file.write(f'WARNING: {CODEFORCE_API_BASE + method} with params {params} failed with status "{data["status"]}" with comment "{data["comment"]}".\n')
                log_file.flush()
                return None, False
        else:
            return r.content.decode("utf-8"), True
    else:
        log_file.write(f'WARNING: {CODEFORCE_API_BASE + method} with params {params} failed with status code "{r.status_code}".\n')
        log_file.flush()
    return None, False
