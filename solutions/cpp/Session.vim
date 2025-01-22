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
badd +2 include/20valid_parentheses.hpp
badd +40 tests/20valid_parentheses_test.cpp
badd +20 tests/1two_sum_test.cpp
badd +1 include/42trapping_rain_water.hpp
badd +1 include/1two_sum.hpp
badd +7 include/155min_stack.hpp
badd +39 tests/155min_stack_test.cpp
badd +35 tests/150evaluate_reverse_polish_notation_test.cpp
badd +2 include/150evaluate_reverse_polish_notation.hpp
badd +1 ~/reference/leetcode.git/master/questions/22.generate-parentheses.txt
badd +27 tests/22generate_parentheses_test.cpp
badd +2 include/22generate_parentheses.hpp
badd +27 include/739daily_temperatures.hpp
badd +28 tests/739daily_temperatures_test.cpp
badd +11 include/853car_fleet.hpp
badd +22 tests/853car_fleet_test.cpp
badd +135 tests/CMakeLists.txt
badd +1 ~/reference/leetcode.git/master/solutions/cpp
argglobal
%argdel
$argadd ~/reference/leetcode.git/master/solutions/cpp
edit include/853car_fleet.hpp
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
exe 'vert 1resize ' . ((&columns * 102 + 106) / 212)
exe 'vert 2resize ' . ((&columns * 109 + 106) / 212)
tcd ~/reference/leetcode.git/master
argglobal
balt ~/reference/leetcode.git/master/solutions/cpp/tests/739daily_temperatures_test.cpp
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
let s:l = 11 - ((10 * winheight(0) + 27) / 54)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 11
normal! 0
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
argglobal
if bufexists(fnamemodify("~/reference/leetcode.git/master/solutions/cpp/tests/853car_fleet_test.cpp", ":p")) | buffer ~/reference/leetcode.git/master/solutions/cpp/tests/853car_fleet_test.cpp | else | edit ~/reference/leetcode.git/master/solutions/cpp/tests/853car_fleet_test.cpp | endif
if &buftype ==# 'terminal'
  silent file ~/reference/leetcode.git/master/solutions/cpp/tests/853car_fleet_test.cpp
endif
balt ~/reference/leetcode.git/master/solutions/cpp/tests/CMakeLists.txt
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
let s:l = 23 - ((22 * winheight(0) + 27) / 54)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 23
normal! 017|
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
exe 'vert 1resize ' . ((&columns * 102 + 106) / 212)
exe 'vert 2resize ' . ((&columns * 109 + 106) / 212)
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
