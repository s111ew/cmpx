const char *ERR_PREFIX = "cmpx: error: ";

const char *ERR_USAGE =
    "Usage: cmpx --algorithm=<algorithm> --input=<input file> --output=<output "
    "file> --operation=<operation>\n"
    "  <algorithm> is the compression algorithm to use\n"
    "  <input file> is the path to the input file\n"
    "  <output file> is the path to the output file\n"
    "  <operation> is the operation to perform (encode or decode)\n";

const char *ERR_ARG_NUM = "Expected 4 args, got %d.\n";
const char *ERR_ARG_ALG_DUP = "Duplicate algorithm argument.\n";
const char *ERR_ARG_OPE_DUP = "Duplicate operation argument.\n";
const char *ERR_ARG_INP_DUP = "Duplicate input argumen.t\n";
const char *ERR_ARG_OUT_DUP = "Duplicate output argument.\n";
const char *ERR_ARG_ALG = "No algorithm %s found.\n";
const char *ERR_ARG_OPE =
    "No operation %s found. Options are 'encode' and 'decode'.\n";
const char *ERR_ARG_NOT_FOUND = "Unrecognised argument(s).\n";
