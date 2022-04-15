#!/usr/bin/env bash
# $0 [shell]

# Default variables.
LOGIN_SHELL="${1:-bash}"
CURRENT_USER_ID=$(id -u)
GROUP_INPUT=$(grep input /etc/group | cut -d':' -f3)

# Starting a new shell on running container.
docker exec \
  -it \
  -u ${CURRENT_USER_ID}:${GROUP_INPUT} \
  $(docker ps -q) \
  ${LOGIN_SHELL}

