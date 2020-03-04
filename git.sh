#!/bin/bash
git add .
echo -e "Default \e[34mAdded changes"
git commit -a --allow-empty-message -m ''
echo -e "Default \e[95mCommited changes"
git push
echo -e "Default \e[32mPushed"