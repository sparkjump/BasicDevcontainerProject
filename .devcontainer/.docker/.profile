# ~/.profile: executed by Bourne-compatible login shells.
echo "Running .profile on '$BASH'"

if [ "$BASH" ]; then
  if [ -z "$SHELL" ]; then
    SHELL="$BASH"
  fi
  export SHELL
  if [ -f ~/.bashrc ]; then
    . ~/.bashrc
  fi
fi

mesg n 2> /dev/null || true