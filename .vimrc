
" Tabstop determines how many columns a tab counts for.
" Shiftwidth determines how many columns text is indented when using reindent operations.
" Expandtab is what actually uses spaces instead of tabs.
set ts=4 shiftwidth=4 expandtab

syntax on
set colorcolumn=80
set incsearch
set hlsearch
colorscheme default
fixdel

set listchars=eol:$,tab:>-

" Status line
set ls=2
highlight StatusLine ctermbg=white ctermfg=blue
set statusline=[File:\ %f]\ [Line:\ %l/%L]   "cursor line/total lines

" Show trailing spaces
highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/

" Update term title but restore old title after leaving Vim
set title
set titleold=

" Plugin CtrlP
set runtimepath^=~/.vim/bundle/ctrlp.vim
let g:ctrlp_map = '<c-p>'
"let g:ctrlp_cmd = 'CtrlP'
"let g:ctrlp_cmd = 'CtrlPMRU'
let g:ctrlp_cmd = 'CtrlPMixed'
"let g:ctrlp_user_command = 'ag %s -l --hidden --nocolor -g ""'
let g:ctrlp_user_command = ['.git', 'cd %s && git ls-files']
"let g:ctrlp_use_caching = 0
let g:ctrlp_clear_cache_on_exit = 0
let g:ctrlp_match_window = 'bottom,order:btt,min:1,max:20,results:20'
