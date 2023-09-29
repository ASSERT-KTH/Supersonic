import generate_predicted_submissions
from parameterized import parameterized
import unittest

class GeneratePredictedSubmissionsTest(unittest.TestCase):

    @parameterized.expand([
            # Empty hunk is not valid
            ('empty', [], False),
            # Addition hunk is valid
            ('addition', [' a\n', '+b\n', ' c\n'], True),
            # Deletion hunk is valid
            ('deletion', [' a\n', '-b\n', ' c\n'], True),
            # Replacement hunk is valid
            ('replacement', [' a\n', '-b\n', '+c\n'], True),
            # Hunk with no '+' or 'c' is not valid
            ('invalid1', [' a\n', ' b\n', ' c\n'], False),
            # '-' should be before '+' in relpacement hunk, not valid
            ('invalid2', [' a\n', '+b\n', '-c\n'], False),
            # Multiple hunks in a single hunk, not valid
            ('invalid3', ['-a\n', ' b\n', '-c\n'], False),

    ])
    def test_is_valid_hunk(self, name, hunk, expected_bool):
        self.assertEqual(generate_predicted_submissions.is_valid_hunk(hunk), expected_bool)

    @parameterized.expand([
        ('get_patch_hunks1',
        (
            '+a\n'
            ' b\n'
            ' c\n'
            '-d\n'
            ' e\n'
        ), ['+a\n b\n', ' c\n-d\n e\n']),
        ('get_patch_hunks2',
        (
            '-a\n'
            '+b\n'
            ' c\n'
            ' d\n'
            '-e\n'
        ), ['-a\n+b\n c\n', ' d\n-e\n']),
        # First hunk is malformed
        ('get_patch_hunks3',
        (
            '+a\n'
            '-b\n'
            ' c\n'
            ' d\n'
            '-e\n'
        ), []),
    ])
    def test_get_patch_hunks(self, name, predicted_patch, expected_hunks):
        hunks = generate_predicted_submissions.get_patch_hunks(predicted_patch)
        self.assertEqual(hunks, expected_hunks)

    @parameterized.expand([
        # Add 'x' before the first line
        ('add_x',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            '+x\n'
            ' b\n'
        ), (
            'x\n'
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        )),
        # Remove 'b'
        ('remove_b',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            ' a\n'
            '-b\n'
            ' c\n'
        ), (
            'a\n'
            'c\n'
            'd\n'
            'e\n'
        )),
        # Replace 'b' with 'x'
        ('replace_b_with_x',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            ' a\n'
            '-b\n'
            '+x\n'
            ' c\n'
        ), (
            'a\n'
            'x\n'
            'c\n'
            'd\n'
            'e\n'
        )),
        # Remove non-existing 'x' results in an empty output
        ('remove_non_existing_x',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            ' a\n'
            '-x\n'
            ' c\n'
        ), ''),
    ])
    def test_apply_predicted_hunk(self, name, original_code, predicted_hunk, expected_original_code):
        self.assertEqual(
            generate_predicted_submissions.apply_predicted_hunk(
                original_code, predicted_hunk),
            expected_original_code)

    @parameterized.expand([
        # Add 'x' before the first line, and remove 'e'.
        ('add_x_remove_e',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            '+x\n'
            ' b\n'
            ' d\n'
            '-e\n'
        ), (
            'x\n'
            'a\n'
            'b\n'
            'c\n'
            'd\n'
        )),
        # Delete all patch
        ('delete_all',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            '-a\n'
            '-b\n'
            '-c\n'
            '-d\n'
            '-e\n'
        ), ''),
        # Replace 'b' and 'c' with 'x' and 'y', replace 'e' with 'z'
        ('delete_all',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            ' a\n'
            '-b\n'
            '-c\n'
            '+x\n'
            '+y\n'
            ' d\n'
            '-e\n'
            '+z\n'
        ), (
            'a\n'
            'x\n'
            'y\n'
            'd\n'
            'z\n'
        )),
        # Remove non-existing 'x'
        ('remove_non_existing_x',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            ' a\n'
            '-x\n'
            ' c\n'
        ), ''),
        # Modifying non-existent content
        ('modifying_non_existent_content',
        (
            'a\n'
            'b\n'
            'c\n'
            'd\n'
            'e\n'
        ), (
            ' e\n'
            '-x\n'
            '+y\n'
        ), ''),
    ])
    def test_apply_patch(self, name, original_code, predicted_patch, expected_original_code):
        self.assertEqual(
            generate_predicted_submissions.apply_patch(
                original_code, predicted_patch),
            expected_original_code)


if __name__ == '__main__':
    unittest.main()