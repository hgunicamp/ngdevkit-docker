#!/usr/bin/env bash
# $0 [shell]

# Default variables.
LOGIN_SHELL="${1:-bash}"
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

# Allowing X11 connection.
xhost +local:${USERNAME}

# Starting a new container.
docker run \
  --rm \
  --device /dev/dri:/dev/dri \
  --device /dev/input:/dev/input \
  -u $(id -u):$(id -g) \
  -e DISPLAY=${DISPLAY} \
  -e XDG_RUNTIME_DIR=${XDG_RUNTIME_DIR} \
  -e HOME=/home/remote \
  -v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -v ${SCRIPT_DIR}/../ngdevkit-server/config/remote:/home/remote \
  -v ${SCRIPT_DIR}/../../projects:/home/remote/projects \
  -w /home/remote/projects \
  -it platform_ngdevkit-server:latest \
  ${LOGIN_SHELL}

# Revoking X11 connection.
xhost -local:${USERNAME}

