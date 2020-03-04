#!/bin/bash
git add .
/bin/echo -e "Default \e[34mAdded changes"
git commit -a --allow-empty-message -m ''
/bin/echo -e "Default \e[95mCommited changes"
git push
/bin/echo -e "Default \e[32mPushed"