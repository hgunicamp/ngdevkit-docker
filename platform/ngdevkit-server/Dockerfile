FROM ubuntu:latest

# Installing essential environment tools.
RUN \
  apt update  && \
  apt install \
  software-properties-common -y

RUN \
  apt install \
  build-essential \
  cmake \
  cmake-extras \
  extra-cmake-modules \
  gpg \
  git-all \
  curl \
  wget \
  exuberant-ctags \
  python3 \
  libkf5config-dev \
  libkf5auth-dev \
  libkf5package-dev \
  libkf5declarative-dev \
  libkf5coreaddons-dev \
  libkf5kcmutils-dev \
  libkf5i18n-dev \
  libqt5core5a \
  libqt5widgets5 \
  libqt5gui5 \
  libqt5qml5 \
  qt5-qmake \
  qtbase5-dev \
  gettext \
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

# Installing KDbg.
RUN cd /tmp && \
  git clone -b maint https://github.com/j6t/kdbg.git && \
  cd kdbg && \
  cmake . && \
  make && \
  make install && \
  cd /tmp && \
  rm -rf kdbg

