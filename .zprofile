#
# ~/.zprofile
#

# Paths
export PATH=$(du "$HOME/.local/bin" | cut -f2 | tr '\n' ':' | sed 's/:*$//'):$PATH

# Variables
export VISUAL="nvim"
export EDITOR="nvim"
export TERMINAL="st"
export PAGER="less"
export BROWSER="chromium"

# XDG base directories
export XDG_CONFIG_HOME="$HOME/.config"
export XDG_DATA_HOME="$HOME/.local/share"
export XDG_CACHE_HOME="$HOME/.cache"
export ZDOTDIR="$XDG_CONFIG_HOME/zsh"
export HISTFILE="$XDG_DATA_HOME/history"
export GTK2_RC_FILES="$XDG_CONFIG_HOME/gtk-2.0/gtkrc-2.0"
export TERMINFO="$XDG_DATA_HOME/terminfo"
export GNUPGHOME="$XDG_DATA_HOME/gnupg"
export WGETRC="$XDG_CONFIG_HOME/wget/wgetrc"
export LESSHISTFILE=-

# LESS config
export LESS='-g -i -M -R -S -w -z-4'
export LESS_TERMCAP_mb="$(printf '%b' '[1;31m')"
export LESS_TERMCAP_md="$(printf '%b' '[1;36m')"
export LESS_TERMCAP_me="$(printf '%b' '[0m')"
export LESS_TERMCAP_so="$(printf '%b' '[01;44;33m')"
export LESS_TERMCAP_se="$(printf '%b' '[0m')"
export LESS_TERMCAP_us="$(printf '%b' '[1;32m')"
export LESS_TERMCAP_ue="$(printf '%b' '[0m')"

# pfetch config
export PF_INFO="ascii title os kernel pkgs memory wm shell term editor palette"

# fzf
export FZF_DEFAULT_COMMAND='fd -t f -L -H -c always'
export FZF_CTRL_T_COMMAND="$FZF_DEFAULT_COMMAND"
export FZF_DEFAULT_OPTS='
	--ansi --border
	--color fg:#D8DEE9,bg:#2E3440,hl:#A3BE8C,fg+:#D8DEE9,bg+:#434C5E,hl+:#A3BE8C
	--color pointer:#BF616A,info:#4C566A,spinner:#4C566A,header:#4C566A,prompt:#81A1C1,marker:#EBCB8B
	--preview "bat --color always --theme="nord" {}" --preview-window :70%'

# Custom lf icons
if [ -f $HOME/.config/lf/icons ]; then
    . $HOME/.config/lf/icons
fi

# Autostart x at login
if systemctl -q is-active graphical.target && [[ ! $DISPLAY && $XDG_VTNR -eq 1 ]]; then
    exec startx "$XDG_CONFIG_HOME/X11/xinitrc"
fi
