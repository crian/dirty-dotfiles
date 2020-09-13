"----------------
" Plugin Manager
"----------------

" Vim-Plug
let vimplug_exists=expand('~/.config/nvim/autoload/plug.vim')

if !filereadable(vimplug_exists)
  if !executable("curl")
    echoerr "You have to install curl or first install vim-plug yourself!"
    execute "q!"
  endif
  echo "Installing Vim-Plug..."
  echo ""
  silent exec "!\curl -fLo " . vimplug_exists . " --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim"
  let g:not_finish_vimplug = "yes"
  autocmd VimEnter * PlugInstall
endif

" Plugins
call plug#begin(expand('~/.config/nvim/plugged'))
Plug 'arcticicestudio/nord-vim'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'ryanoasis/vim-devicons'
Plug 'junegunn/goyo.vim'
Plug 'neoclide/coc.nvim', {'do': 'yarn install --frozen-lockfile'}
Plug 'junegunn/fzf.vim'
Plug 'honza/vim-snippets'
Plug 'SirVer/ultisnips'
Plug 'Yggdroot/indentLine'
Plug 'jiangmiao/auto-pairs'
Plug 'sheerun/vim-polyglot'
Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutter'
Plug 'jreybert/vimagit'
Plug 'psliwka/vim-smoothie'
Plug 'farmergreg/vim-lastplace'
Plug 'liuchengxu/vista.vim'
Plug 'tpope/vim-eunuch'
Plug 'easymotion/vim-easymotion'
Plug '907th/vim-auto-save'
Plug 'norcalli/nvim-colorizer.lua'
Plug 'lambdalisue/suda.vim'
Plug 'luochen1990/rainbow'
call plug#end()

"------------------
" General settings
"------------------

set termguicolors                                       " Opaque Background
set mouse=a                                             " enable mouse scrolling
set clipboard+=unnamedplus                              " use system clipboard by default
filetype plugin indent on                               " enable indentations
set tabstop=4 softtabstop=4 shiftwidth=4 autoindent     " tab key actions
set expandtab                                           " convert tabs to spaces
set incsearch ignorecase smartcase hlsearch             " highlight text while searching
set list listchars=trail:»,tab:»-                       " use tab to navigate in list mode
set fillchars+=vert:\▏                                  " requires a patched nerd font
"set wrap breakindent                                   " wrap long lines to the width set by tw
"set tw=90                                              " auto wrap lines that are longer than that
set encoding=utf-8                                      " text encoding
set number                                              " enable numbers on the left
set relativenumber                                      " current line is 0
set noshowmode                                          " disable showing modes
set title                                               " tab title as file file
set conceallevel=2                                      " set this so we wont break indentation plugin
set splitright                                          " open vertical split to the right
set splitbelow                                          " open horizontal split to the bottom
set emoji                                               " enable emojis
let g:indentLine_setConceal = 0                         " actually fix the annoying markdown links conversion
au BufEnter * set fo-=c fo-=r fo-=o                     " stop annoying auto commenting on new lines
set history=1000                                        " history limit
set backspace=indent,eol,start                          " sensible backspacing
set undofile                                            " enable persistent undo
set undodir=/tmp//                                      " undo temp file directory
set backupdir=/tmp//                                    " backup temp file directory
set directory=/tmp//                                    " swap temp file directory
set foldlevel=0                                         " open all folds by default
set inccommand=nosplit                                  " visual feedback while substituting
let loaded_netrw = 0                                    " diable netew
let g:omni_sql_no_default_maps = 1                      " disable sql omni completion
"set timeout timeoutlen=1000                            " longer leader key timeout
set autoread                                            " re-read file if changed outside vim
set lazyredraw                                          " no redraw wihle executing macros,...
set redrawtime=10000                                    " redraw time
set synmaxcol=180                                       " avoid very slow redrawing
" required by coc
set hidden                                              " hide buffer when abandoned
"set nobackup                                           " no backup file
"set nowritebackup                                      " no backup before overwriting file
set cmdheight=2                                         " number of lines for command-line
set updatetime=300                                      " milliseconds before writing swap
set shortmess+=c                                        " don't give |ins-completion-menu| messages
set signcolumn=yes                                      " always draw signcolumn

" Colors
set background=dark
colorscheme nord
let g:airline_theme='nord'
highlight Pmenu guifg=white                             " popup menu colors
highlight Comment gui=italic cterm=italic               " italic comments
highlight Normal gui=none
highlight NonText guibg=none
highlight clear SignColumn                              " use number color for sign column color
hi Search guibg=#b16286 guifg=#ebdbb2 gui=NONE          " search string highlight color
autocmd ColorScheme * highlight VertSplit cterm=NONE    " split color
hi NonText guifg=bg                                     " mask ~ on empty lines
hi clear CursorLineNr                                   " use the theme color for relative number
hi CursorLineNr gui=bold                                " make relative number bold
hi EasyMotionMoveHL guibg=#b16286 guifg=#ebdbb2 gui=NONE
" colors for git (especially the gutter)
hi DiffAdd  guibg=#0f111a guifg=#43a047
hi DiffChange guibg=#0f111a guifg=#fdd835
hi DiffRemoved guibg=#0f111a guifg=#e53935
" coc multi cursor highlight color
hi CocCursorRange guibg=#b16286 guifg=#ebdbb2

"-----------------
" Plugin settings
"-----------------

" Airline
let g:airline_powerline_fonts = 0
let g:airline#themes#clean#palette = 1
call airline#parts#define_raw('linenr', '%l')
call airline#parts#define_accent('linenr', 'bold')
let g:airline_section_z = airline#section#create(['%3p%%  ',
            \ g:airline_symbols.linenr .' ', 'linenr', ':%c '])
let g:airline_section_warning = ''
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#fnamemod = ':t'
let g:airline#extensions#ale#enabled = 1
let g:airline#extensions#coc#enabled = 1
let g:airline#extensions#unicode#enabled = 1
let g:airline#extensions#branch#enabled = 1
let g:airline#extensions#vista#enabled = 1
let g:airline#extensions#hunks#enabled = 1
let airline#extensions#coc#stl_format_err = '%E{[%e(#%fe)]}'
let airline#extensions#coc#stl_format_warn = '%W{[%w(#%fw)]}'
let airline#extensions#coc#warning_symbol = ':'
let airline#extensions#coc#error_symbol = ':'
let g:airline#extensions#hunks#hunk_symbols = [':', ':', ':']
let g:airline#extensions#branch#format = 2

"" Conquer of Completion
" use tab for completion trigger
inoremap <silent><expr> <TAB>
      \ pumvisible() ? "\<C-n>" :
      \ <SID>check_back_space() ? "\<TAB>" :
      \ coc#refresh()
inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"
" Navigate snippet placeholders using tab
let g:coc_snippet_next = '<Tab>'
let g:coc_snippet_prev = '<S-Tab>'
" Use enter to accept snippet expansion
inoremap <expr> <cr> pumvisible() ? "\<C-y>" : "\<CR>"
function! s:check_back_space() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction
let g:coc_snippet_next = '<tab>'
autocmd! CompleteDone * if pumvisible() == 0 | pclose | endif
" list of the extensions required
let g:coc_global_extensions = [
            \'coc-yank',
            \'coc-json',
            \'coc-lists',
            \'coc-syntax',
            \'coc-git',
            \'coc-snippets',
            \'coc-ultisnips',
            \]

" indentLine
let g:indentLine_char_list = ['|', '¦', '┆', '┊']
let g:indentLine_color_gui = '#565969'

" rainbow brackets
let g:rainbow_active = 1

" easymotion
let g:EasyMotion_startofline = 0
let g:EasyMotion_smartcase = 1

" auto save
let g:auto_save        = 0
let g:auto_save_silent = 1
let g:auto_save_events = ["InsertLeave", "TextChanged", "FocusLost"]

"" FZF
" general
let g:fzf_layout = { 'window': 'call CreateCenteredFloatingWindow()' }
let $FZF_DEFAULT_OPTS="--reverse "
" use rg by default
if executable('rg')
  let $FZF_DEFAULT_COMMAND = 'rg --files --hidden --follow --glob "!.git/*"'
  set grepprg=rg\ --vimgrep
endif

" Colorizer
lua require'colorizer'.setup()

" Suda
let g:suda_smart_edit = 1

" Auto Pairs
let g:AutoPairsMultilineClose = 0

" Gitgutter
let g:gitgutter_enabled = 1
let g:gitgutter_grep=''

" Vista
let g:vista_executive_for = {
      \ 'c': 'coc',
      \ }
let g:vista_icon_indent = ["╰─▸ ", "├─▸ "]
let g:vista#renderer#enable_icon = 1
let g:vista_sidebar_width = 50

"---------------
" Auto commands
"---------------

" enable spell only if file type is normal text
let spellable = ['markdown', 'gitcommit', 'txt', 'text']
autocmd BufEnter * if index(spellable, &ft) < 0 | set nospell | else | set spell | endif

" open help in vertical split
autocmd FileType help wincmd L

" open files preview on enter and provided arg is a folder
autocmd VimEnter * if argc() != 0 && isdirectory(argv()[0]) | execute 'cd' fnameescape(argv()[0])  | endif
autocmd VimEnter * if argc() != 0 && isdirectory(argv()[0]) | Files | endif

" relative numbers on normal mode only
augroup numbertoggle
    autocmd!
    autocmd InsertLeave * set relativenumber
    autocmd InsertEnter * set norelativenumber
augroup END

" remove trialing whitespaces and newline on save
autocmd BufWritepre * %s/\n\+\%$//e

"-----------
" Functions
"-----------

" files window with preview
command! -bang -nargs=? -complete=dir Files
        \ call fzf#vim#files(<q-args>, fzf#vim#with_preview(), <bang>0)

" advanced grep(faster with preview)
function! RipgrepFzf(query, fullscreen)
    let command_fmt = 'rg --column --line-number --no-heading --color=always --smart-case %s || true'
    let initial_command = printf(command_fmt, shellescape(a:query))
    let reload_command = printf(command_fmt, '{q}')
    let spec = {'options': ['--phony', '--query', a:query, '--bind', 'change:reload:'.reload_command]}
    call fzf#vim#grep(initial_command, 1, fzf#vim#with_preview(spec), a:fullscreen)
endfunction
command! -nargs=* -bang Rg call RipgrepFzf(<q-args>, <bang>0)

" floating fzf window with borders
function! CreateCenteredFloatingWindow()
    let width = min([&columns - 4, max([80, &columns - 20])])
    let height = min([&lines - 4, max([20, &lines - 10])])
    let top = ((&lines - height) / 2) - 1
    let left = (&columns - width) / 2
    let opts = {'relative': 'editor', 'row': top, 'col': left, 'width': width, 'height': height, 'style': 'minimal'}

    let top = "╭" . repeat("─", width - 2) . "╮"
    let mid = "│" . repeat(" ", width - 2) . "│"
    let bot = "╰" . repeat("─", width - 2) . "╯"
    let lines = [top] + repeat([mid], height - 2) + [bot]
    let s:buf = nvim_create_buf(v:false, v:true)
    call nvim_buf_set_lines(s:buf, 0, -1, v:true, lines)
    call nvim_open_win(s:buf, v:true, opts)
    set winhl=Normal:Floating
    let opts.row += 1
    let opts.height -= 2
    let opts.col += 2
    let opts.width -= 4
    call nvim_open_win(nvim_create_buf(v:false, v:true), v:true, opts)
    au BufWipeout <buffer> exe 'bw '.s:buf
endfunction

" show docs on things with K
function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction

" Add `:Format` command to format current buffer.
command! -nargs=0 Format :call CocAction('format')

" Add `:OR` command for organize imports of the current buffer.
command! -nargs=0 OR :call CocAction('runCommand', 'editor.action.organizeImport')

" Toggle Tabs/Spaces
function! TabToggle()
    if &expandtab
        set shiftwidth=4
        set softtabstop=0
        set noexpandtab
    else
        set shiftwidth=4
        set softtabstop=4
        set expandtab
    endif
endfunction

"----------
" Mappings
"----------

" general
let mapleader=","
nnoremap ; :
nmap <leader>w :w<CR>
nmap <leader>wq :wq<CR>
noremap <C-q> :q!<CR>
nmap <leader>q :bd<CR>
nmap \ <leader>q
noremap <leader>e :PlugInstall<CR>
nmap <leader>r :so ~/.config/nvim/init.vim<CR>
nmap <Tab> :bnext<CR>
nmap <S-Tab> :bprevious<CR>
nnoremap <silent> <leader>f :Files<CR>
nmap <leader>b :Buffers<CR>
nmap <leader>c :Commands<CR>
map <leader>rg :Rg<CR>
map <leader>v :Vista finder<CR>
map <F4> :Vista!!<CR>
nmap <leader>g :Goyo<CR>
noremap <silent> <esc><esc> :noh<return>
nmap <F9> mz:execute TabToggle()<CR>'z

" use a different buffer for dd
nnoremap d "_d
vnoremap d "_d

" emulate windows copy/cut behavior
vnoremap <C-c> "+y<CR>
vnoremap <C-x> "+d<CR>

" switch between splits using ctrl + {h,j,k,l}
tnoremap <C-h> <C-\><C-N><C-w>h
tnoremap <C-j> <C-\><C-N><C-w>j
tnoremap <C-k> <C-\><C-N><C-w>k
tnoremap <C-l> <C-\><C-N><C-w>l
inoremap <C-h> <C-\><C-N><C-w>h
inoremap <C-j> <C-\><C-N><C-w>j
inoremap <C-k> <C-\><C-N><C-w>k
inoremap <C-l> <C-\><C-N><C-w>l
nnoremap <C-h> <C-w>h
noremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l

"" coc mappings
" multi cursor shortcuts
nmap <silent> <C-c> <Plug>(coc-cursors-position)
nmap <silent> <C-a> <Plug>(coc-cursors-word)
xmap <silent> <C-a> <Plug>(coc-cursors-range)
" Use `[g` and `]g` to navigate diagnostics
nmap <silent> [g <Plug>(coc-diagnostic-prev)
nmap <silent> ]g <Plug>(coc-diagnostic-next)
" for global rename
nmap <leader>rn <Plug>(coc-rename)
" GoTo code navigation
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)
" Use K to show documentation in preview window
nnoremap <silent> K :call <SID>show_documentation()<CR>

"" easy motion stuff
" search
map  / <Plug>(easymotion-sn)
omap / <Plug>(easymotion-tn)
map  n <Plug>(easymotion-next)
map  N <Plug>(easymotion-prev)
" navigation
map <Leader>l <Plug>(easymotion-lineforward)
map <Leader>j <Plug>(easymotion-j)
map <Leader>k <Plug>(easymotion-k)
map <Leader>h <Plug>(easymotion-linebackward)

" fugitive mappings
map <leader>d :Gdiffsplit<CR>

" Vimagit
map <leader>m :Magit<CR>
