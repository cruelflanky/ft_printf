#!/bin/bash

GREEN = \033[0;32m
RED = \033[0;31m

git add .
echo "$(GREEN)Added changes"
git commit -a --allow-empty-message -m ''
echo -e "Default \e[95mCommited changes"
git push
echo -e "Default \e[32mPushed"