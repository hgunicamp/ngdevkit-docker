#!/usr/bin/env bash

# Default variables.
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
NG_DEVKIT_BASE_DIR=${SCRIPT_DIR}/../

# Changing folder to start the building process.
cd ${NG_DEVKIT_BASE_DIR}
docker-compose build
