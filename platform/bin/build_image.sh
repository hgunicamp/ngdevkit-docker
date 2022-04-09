#!/usr/bin/env bash

# Default variables.
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
NG_DEVKIT_DIR=${SCRIPT_DIR}/../ngdevkit-server

# Changing folder to start the building process.
cd ${NG_DEVKIT_DIR}
docker-compose build
