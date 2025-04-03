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
badd +267 tests/CMakeLists.txt
badd +14 include/143reorder_list.hpp
badd +1 CMakeLists.txt
badd +11 ~/reference/leetcode.git/master/questions/19.remove-nth-node-from-end-of-list.txt
badd +20 tests/19remove_nth_node_from_end_of_list_test.cpp
badd +52 include/19remove_nth_node_from_end_of_list.hpp
badd +55 ~/reference/leetcode.git/master/questions/138.copy-list-with-random-pointer.txt
badd +22 include/138copy_list_with_random_pointer.hpp
badd +4 tests/138copy_list_with_random_pointer_test.cpp
badd +0 ~/reference/leetcode.git/master/solutions/cpp
argglobal
%argdel
$argadd ~/reference/leetcode.git/master/solutions/cpp
edit tests/138copy_list_with_random_pointer_test.cpp
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
exe 'vert 1resize ' . ((&columns * 115 + 115) / 231)
exe 'vert 2resize ' . ((&columns * 115 + 115) / 231)
tcd ~/reference/leetcode.git/master
argglobal
balt ~/reference/leetcode.git/master/solutions/cpp/include/138copy_list_with_random_pointer.hpp
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
let s:l = 5 - ((1 * winheight(0) + 12) / 24)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 5
normal! 0
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
argglobal
if bufexists(fnamemodify("~/reference/leetcode.git/master/solutions/cpp/tests/CMakeLists.txt", ":p")) | buffer ~/reference/leetcode.git/master/solutions/cpp/tests/CMakeLists.txt | else | edit ~/reference/leetcode.git/master/solutions/cpp/tests/CMakeLists.txt | endif
if &buftype ==# 'terminal'
  silent file ~/reference/leetcode.git/master/solutions/cpp/tests/CMakeLists.txt
endif
balt ~/reference/leetcode.git/master/solutions/cpp/tests/19remove_nth_node_from_end_of_list_test.cpp
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
let s:l = 280 - ((14 * winheight(0) + 12) / 24)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 280
normal! 033|
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 115 + 115) / 231)
exe 'vert 2resize ' . ((&columns * 115 + 115) / 231)
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
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
