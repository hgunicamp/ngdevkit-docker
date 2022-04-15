#!/usr/bin/env bash
# Use: $0 <elf-file> <gdb-port> <host>

# Default values.
ELF_FILE="${1:-rom.elf}"
PORT="${2:-2159}"
HOST="${3:-localhost}"

# Debugger executable.
kdbg -r ${HOST}:${PORT} ${ELF_FILE}
