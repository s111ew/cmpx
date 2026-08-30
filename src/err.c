const char *ERR_PREFIX = "cmpx: error:";

const char *ERR_USAGE =
    "Usage: cmpx --algorithm=<algorithm> --input=<input file> --output=<output "
    "file> --operation=<operation>\n"
    "  <algorithm> is the compression algorithm to use\n"
    "  <input file> is the path to the input file\n"
    "  <output file> is the path to the output file\n"
    "  <operation> is the operation to perform (encode or decode)\n";

const char *ERR_ARG_COUNT = "Expected 4 args got:";
const char *ERR_ARG_DUPLICATE = "Duplicate argument:";
const char *ERR_ARG_VALUE = "Unrecognised value:";
const char *ERR_ARG_NOT_FOUND = "Unrecognised argument:";

const char *ERR_IO_OPEN = "Failed to open file:";
const char *ERR_IO_OPEN_OR_CREATE = "Failed to open or create file:";
const char *ERR_IO_METADATA = "Failed to fetch metadata for file:";
const char *ERR_IO_ALLOC = "Failed to allocate memory file of size:";
const char *ERR_IO_READ = "Failed to read file (bytes read):";
const char *ERR_IO_CLOSE = "Failed to close file:";
const char *ERR_IO_WRITE =
    "Failed to write file (bytes written/bytes expected):";
const char *ERR_IO_PATH = "Failed to resolve file path:";

const char *ERR_CODEC_NOT_FOUND = "Failed to find codec:";
