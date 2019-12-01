#!/bin/bash

echo "what is your user :"
read user
echo "\n"
echo "what is your email :"
read email
echo "\n"
git init
echo "run : git config --global user.email $email"
git config --global user.email $email
echo "run : git conifg --global user.name $user"
git config --global user.name $name
