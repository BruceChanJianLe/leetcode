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
badd +5 include/238product_of_array_except_self.hpp
badd +27 tests/36valid_sudoku_test.cpp
badd +49 include/36valid_sudoku.hpp
badd +74 tests/CMakeLists.txt
badd +1 fugitive:///home/developer/reference/leetcode.git/worktrees/master//
badd +22 ~/reference/leetcode.git/master/questions/128.longest-consecutive-sequence.txt
badd +26 include/128longest_consecutive_sequence.hpp
badd +28 tests/128longest_consecutive_sequence_test.cpp
badd +1 tests/167two_sum_ii_test.cpp
argglobal
%argdel
$argadd ~/reference/leetcode.git/master/solutions/cpp/
edit tests/CMakeLists.txt
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
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
exe '1resize ' . ((&lines * 20 + 22) / 44)
exe 'vert 1resize ' . ((&columns * 83 + 83) / 167)
exe '2resize ' . ((&lines * 20 + 22) / 44)
exe 'vert 2resize ' . ((&columns * 83 + 83) / 167)
exe '3resize ' . ((&lines * 20 + 22) / 44)
tcd ~/reference/leetcode.git/master
argglobal
balt ~/reference/leetcode.git/master/solutions/cpp/tests/128longest_consecutive_sequence_test.cpp
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
let s:l = 74 - ((14 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 74
normal! 0
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
argglobal
if bufexists(fnamemodify("~/reference/leetcode.git/master/solutions/cpp/include/128longest_consecutive_sequence.hpp", ":p")) | buffer ~/reference/leetcode.git/master/solutions/cpp/include/128longest_consecutive_sequence.hpp | else | edit ~/reference/leetcode.git/master/solutions/cpp/include/128longest_consecutive_sequence.hpp | endif
if &buftype ==# 'terminal'
  silent file ~/reference/leetcode.git/master/solutions/cpp/include/128longest_consecutive_sequence.hpp
endif
balt ~/reference/leetcode.git/master/solutions/cpp/tests/128longest_consecutive_sequence_test.cpp
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
let s:l = 28 - ((13 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 28
normal! 0
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
argglobal
if bufexists(fnamemodify("fugitive:///home/developer/reference/leetcode.git/worktrees/master//", ":p")) | buffer fugitive:///home/developer/reference/leetcode.git/worktrees/master// | else | edit fugitive:///home/developer/reference/leetcode.git/worktrees/master// | endif
if &buftype ==# 'terminal'
  silent file fugitive:///home/developer/reference/leetcode.git/worktrees/master//
endif
balt ~/reference/leetcode.git/master/solutions/cpp/tests/CMakeLists.txt
setlocal fdm=manual
setlocal fde=0
setlocal fmr=<<<<<<<<,>>>>>>>>
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 6 - ((5 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 6
normal! 0
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
3wincmd w
exe '1resize ' . ((&lines * 20 + 22) / 44)
exe 'vert 1resize ' . ((&columns * 83 + 83) / 167)
exe '2resize ' . ((&lines * 20 + 22) / 44)
exe 'vert 2resize ' . ((&columns * 83 + 83) / 167)
exe '3resize ' . ((&lines * 20 + 22) / 44)
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
