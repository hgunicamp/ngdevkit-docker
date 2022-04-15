FROM ubuntu:latest

# Installing essential environment tools.
RUN \
  apt update  && \
  apt install \
  software-properties-common -y

RUN \
  apt install \
  build-essential \
  gpg \
  git-all \
  curl \
  wget \
  exuberant-ctags \
  python3 \
  qt5-qmake \
  qtbase5-dev \
  vim \
  zsh \
  zplug \
  zsh-syntax-highlighting \
  zsh-autosuggestions -y

# Installing ngdevkit tools.
RUN \
  add-apt-repository -y ppa:dciabrin/ngdevkit && \
  apt update && \
  apt install \
  ngdevkit \
  ngdevkit-gngeo -y && \
  apt install \
  pkg-config \
  autoconf \
  zip \
  imagemagick \
  sox \
  libsox-fmt-mp3 -y

# Installing GDB tools.
ENV GEDE_VERSION=2.18.2
ENV GEDE_SRC_DIR=gede-${GEDE_VERSION}
ENV GEDE_PACKAGE=${GEDE_SRC_DIR}.tar.xz

RUN cd /tmp && \
  wget http://gede.dexar.se/uploads/source/${GEDE_PACKAGE} && \
  tar --use-compress-program xz -xf ${GEDE_PACKAGE} && \
  cd ${GEDE_SRC_DIR} && \
  make install && \
  cd /tmp && \
  rm -rf ${GEDE_PACKAGE} ${GEDE_SRC_DIR}

