#!/usr/bin/env bash
# $0 [shell]

# Default values.
TARGET_SHELL="${1:-bash}"
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
RUNNING_DOCKER="$(docker ps | grep platform_ngdevkit-server)"
NEW_DOCKER_CONTAINER_SH="login_user.sh"
ATTACH_DOCKER_CONTAINER_SH="new_shell.sh"

# Triggering the right script.
if [ "x" == "x${RUNNING_DOCKER}" ]; then
  COMMAND="${SCRIPT_DIR}/${NEW_DOCKER_CONTAINER_SH} ${TARGET_SHELL}"
else
  COMMAND="${SCRIPT_DIR}/${ATTACH_DOCKER_CONTAINER_SH} ${TARGET_SHELL}"
fi

# Final command.
$COMMAND
