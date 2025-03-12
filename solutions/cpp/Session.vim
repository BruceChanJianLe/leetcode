let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/reference/leetcode.git/master/solutions/cpp
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +160 tests/CMakeLists.txt
badd +37 ~/reference/leetcode.git/master/questions/3.longest-substring-without-repeating-characters.txt
badd +19 tests/3longest_substring_without_repeating_characters_test.cpp
badd +35 include/3longest_substring_without_repeating_characters.hpp
badd +1 ~/reference/leetcode.git/master/solutions/cpp
argglobal
%argdel
$argadd ~/reference/leetcode.git/master/solutions/cpp
edit tests/3longest_substring_without_repeating_characters_test.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 93 + 102) / 205)
exe 'vert 2resize ' . ((&columns * 111 + 102) / 205)
tcd ~/reference/leetcode.git/master
argglobal
balt ~/reference/leetcode.git/master/solutions/cpp/include/3longest_substring_without_repeating_characters.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 19 - ((8 * winheight(0) + 12) / 25)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 19
normal! 0
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
argglobal
if bufexists(fnamemodify("~/reference/leetcode.git/master/solutions/cpp/include/3longest_substring_without_repeating_characters.hpp", ":p")) | buffer ~/reference/leetcode.git/master/solutions/cpp/include/3longest_substring_without_repeating_characters.hpp | else | edit ~/reference/leetcode.git/master/solutions/cpp/include/3longest_substring_without_repeating_characters.hpp | endif
if &buftype ==# 'terminal'
  silent file ~/reference/leetcode.git/master/solutions/cpp/include/3longest_substring_without_repeating_characters.hpp
endif
balt ~/reference/leetcode.git/master/solutions/cpp/tests/3longest_substring_without_repeating_characters_test.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 35 - ((14 * winheight(0) + 12) / 25)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 35
normal! 028|
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
exe 'vert 1resize ' . ((&columns * 93 + 102) / 205)
exe 'vert 2resize ' . ((&columns * 111 + 102) / 205)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
