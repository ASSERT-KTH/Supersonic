import setuptools

setuptools.setup(
    name='extract_func_pairs_beam',
    version='0.1.0',
    install_requires=['libclang', 'timeout-decorator', 'unidiff'],
    packages=['beam'],
)
