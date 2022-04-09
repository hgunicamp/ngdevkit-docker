FROM ubuntu:latest

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
  vim \
  zsh \
  zplug \
  zsh-syntax-highlighting \
  zsh-autosuggestions -y

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

