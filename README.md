# Pattern-Matching

This code implements a pattern matching functionality that can identify whether a target string matches a specific pattern.

### Supported Patterns

The supported pattern syntax includes:

- `+`: Matches a single alphabetic character (a-z or A-Z).
- `*`: Matches a sequence of three repeated characters by default.
- `*{N}`: Matches a sequence of N repeated characters, where N is a positive integer.

### Usage

1. Compile the code (e.g., using g++ patternMatch.cpp -o patternMatch).
2. Run the executable with the following syntax:

   ```bash
   ./pattern_matching "pattern target"
   ```

   - `pattern`: The pattern to match against the target string.
   - `target`: The string to check for a match with the pattern.

### Examples

```bash
./pattern_matching "++* hello"    # Output: Pattern Match is: false (Pattern doesn't match "hello")
./pattern_matching "++*{5} gheeeee"  # Output: Pattern Match is: true (Matches "gheeeee")
./pattern_matching "++* world"     # Output: Pattern Match is: false (Pattern doesn't match "world")
```

### Code Functionality

The code defines two main functions:

- `patternMatching(string str)`: This function takes the combined pattern and target string as input and performs the matching logic. It iterates through both the pattern and target string, checking for character matches and handling the different pattern constructs.
- `main(int argc, char* argv[])`: This function parses command-line arguments, validates the input format, and calls `patternMatching` with the combined pattern and target string. It then outputs the result ("true" if there's a match, "false" otherwise).

### Additional Notes

- The code currently assumes well-formed input. Error handling for invalid patterns or missing arguments could be added.
- For efficiency, advanced algorithms like Knuth-Morris-Pratt (KMP) could be explored for pattern matching, especially when dealing with longer patterns or frequent matching operations.

