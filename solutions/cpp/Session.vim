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
badd +35 include/238product_of_array_except_self.hpp
badd +27 tests/36valid_sudoku_test.cpp
badd +19 include/36valid_sudoku.hpp
badd +3 tests/CMakeLists.txt
badd +22 ~/reference/leetcode.git/master/questions/128.longest-consecutive-sequence.txt
badd +43 include/128longest_consecutive_sequence.hpp
badd +54 tests/128longest_consecutive_sequence_test.cpp
badd +8 tests/167two_sum_ii_test.cpp
badd +16 ~/reference/leetcode.git/master/questions/125.valid-palindrome.txt
badd +16 tests/125valid_palindrome_test.cpp
badd +24 include/125valid_palindrome.hpp
badd +1 ~/reference/leetcode.git/master/solutions/cpp
badd +14 include/217contains_duplicate.hpp
badd +17 include/242valid_anagram.hpp
badd +10 include/1two_sum.hpp
badd +19 include/49group_anagrams.hpp
badd +4 include/347top_k_frequent_elements.hpp
badd +1 CMakeLists.txt
badd +47 tests/347top_k_frequent_elements_test.cpp
badd +39 include/271encode_and_decode_strings.hpp
badd +41 tests/238product_of_array_except_self_test.cpp
argglobal
%argdel
$argadd ~/reference/leetcode.git/master/solutions/cpp
edit include/125valid_palindrome.hpp
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
exe 'vert 1resize ' . ((&columns * 102 + 102) / 205)
exe 'vert 2resize ' . ((&columns * 102 + 102) / 205)
tcd ~/reference/leetcode.git/master
argglobal
balt ~/reference/leetcode.git/master/solutions/cpp/include/128longest_consecutive_sequence.hpp
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
let s:l = 24 - ((22 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 24
normal! 048|
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
argglobal
if bufexists(fnamemodify("~/reference/leetcode.git/master/solutions/cpp/tests/125valid_palindrome_test.cpp", ":p")) | buffer ~/reference/leetcode.git/master/solutions/cpp/tests/125valid_palindrome_test.cpp | else | edit ~/reference/leetcode.git/master/solutions/cpp/tests/125valid_palindrome_test.cpp | endif
if &buftype ==# 'terminal'
  silent file ~/reference/leetcode.git/master/solutions/cpp/tests/125valid_palindrome_test.cpp
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
let s:l = 19 - ((18 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 19
normal! 0
lcd ~/reference/leetcode.git/master/solutions/cpp
wincmd w
exe 'vert 1resize ' . ((&columns * 102 + 102) / 205)
exe 'vert 2resize ' . ((&columns * 102 + 102) / 205)
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
