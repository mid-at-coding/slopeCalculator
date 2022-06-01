#!/bin/sh

if [ -d "~/bin" ]
  echo "~/bin exists"
else
  echo "~/bin does not exist. Would you like to create it? [Y/n] "
  read createDir
  
  if [[$createDir == "y" || $createDir == "Y" || $createDir == "yes" || $createDir == "Yes" || $createDir == "YES" || $createDir == ""]]
    mkdir ~/bin/
    exitStatus=$?
    
    if [[$exitStatus == 0]]
      echo "created ~/bin"
    else
      exit 1
  else
    exit 1
  fi
fi

grep -qx 'PATH="$PATH:$HOME/bin/"' ~/.profile     # Checks if ~/bin is a $PATH

exitStatus=$?

if [[$exitStatus == 1]]
  echo "~/bin is not in your PATH. would you like to add it? [Y/n]"
  
  read addPath
  
  if [[$addpath == "y" || $addpath == "Y" || $addpath == "yes" || $addpath == "Yes" || $addpath == "YES" || $addpath == ""]]
    echo 'PATH="$PATH:$HOME/bin/"' >> ~/.profile    # Adds the path if it isn't there
  else
    exit 1
  fi
fi

g++ calc.cpp -o ~/bin/calc
