#!/usr/bin/env bash

#MISE description="🧼 Delete build and cache files | alias = clean"
#MISE quiet=true

rm -rf build
rm -rf .cache

printf "\n%s\n\n" '✅ build and cache files have been deleted'
