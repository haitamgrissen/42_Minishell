if ! command -v brew &> /dev/null
then
  export HOME_BREW="/Users/$USER/goinfre/$USER"
  rm -rf $HOME/.brew && rm -rf $HOME_BREW/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME_BREW/.brew
	echo	"export HOME_BREW=\"/Users/$USER/goinfre/$USER\""	>> ~/.zshrc
	echo	"export PATH=$HOME_BREW/.brew/bin:$PATH" >> ~/.zshrc

fi
#export SB="/Users/$USER"

#rm -rf $HOME/.brew && rm -rf $SB/.brew && git clone --depth=1 https://github.com/Homebrew/brew $SB/.brew
#echo	"export PATH=\"$SB/.brew/bin:$PATH\"" >> ~/.zshrc

#echo	'alias brewgf="$HOME_BREW/.brew/bin/brew"'
#echo	'alias brews="$SB/.brew/bin/brew"'