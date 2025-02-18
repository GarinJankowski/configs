set nocompatible
filetype off
syntax on
filetype plugin indent on 

set modelines=0
set number
set ruler
set encoding=utf-8
set wrap
set textwidth=79
set formatoptions=tcqrn1
set tabstop=2
set shiftwidth=2
set softtabstop=2
set expandtab
set noshiftround
set scrolloff=9999
set backspace=indent,eol,start
set matchpairs+=<:> " use % to jump between pairs
runtime! macros/matchit.vim
set hidden
set ttyfast
set laststatus=2
set showmode
set showcmd
set hlsearch
set incsearch
set ignorecase
set smartcase
set showmatch
colorscheme sorbet

hi StatusLine ctermbg=NONE ctermfg=NONE guibg=NONE guifg=NONE
hi StatusLineNC ctermbg=NONE ctermfg=NONE guibg=NONE guifg=NONE
