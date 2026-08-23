const char *ERR_PREFIX = "cmpx: error: ";

const char *ERR_USAGE =
    "Usage: cmpx --algorithm=<algorithm> --input=<input file> --output=<output "
    "file> --operation=<operation>\n"
    "  <algorithm> is the compression algorithm to use\n"
    "  <input file> is the path to the input file\n"
    "  <output file> is the path to the output file\n"
    "  <operation> is the operation to perform (encode or decode)\n";

const char *ERR_ARG_COUNT = "Expected 4 args, got %d.\n";
const char *ERR_ARG_DUPLICATE = "Duplicate %s argument.\n";
const char *ERR_ARG_VALUE = "No %s '%s' found.\n";
const char *ERR_ARG_NOT_FOUND = "Unrecognised argument(s).\n";
