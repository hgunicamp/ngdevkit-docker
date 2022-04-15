#!/usr/bin/env bash

kill -9 $(ps | grep ngdevkit-gngeo | tr -s ' ' ' ' | cut -f2 -d' ')
