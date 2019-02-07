.586
	.model flat, stdcall
	includelib libucrt.lib
	includelib libucrt.lib
	includelib kernel32.lib
	ExitProcess PROTO :DWORD

	includelib ../Debug/PASlib.lib
	writes PROTO :DWORD
	writed PROTO :DWORD
	strl PROTO :DWORD
	degree PROTO :DWORD, :DWORD
	radical PROTO :DWORD, :DWORD
	degree PROTO :DWORD, :DWORD


.stack 4096
.const
	literal0 DWORD 2
	literal1 DWORD 3
	literal2 DWORD 5
	literal3 DWORD 10
	literal4 BYTE 'Hello World', 0
	literal5 BYTE 'Google', 0
	literal6 BYTE '10111997', 0
	literal7 DWORD 0
.data
	zfun0 DWORD ?
	tfun0 DWORD ?
	sfun0 DWORD ?
	cfun1 DWORD ?
	xbir DWORD ?
	ybir DWORD ?
	zbir DWORD ?
	sabir DWORD ?
	sbbir DWORD ?

.code
fund PROC yfun0:DWORD, xfun0:DWORD
push xfun0
push literal0
call degree
push eax
pop zfun0

push yfun0
push literal1
call radical
push eax
pop tfun0

push xfun0
push zfun0
push tfun0
pop eax
pop ebx
add eax, ebx
push eax
pop eax
pop ebx
mul ebx
push eax
pop sfun0

	mov eax, sfun0
	ret
fund ENDP

funs PROC bfun1:DWORD, afun1:DWORD
push afun1
call strl
push eax
push bfun1
pop ebx
pop eax
sub eax, ebx
push eax
pop cfun1

	mov eax, cfun1
	ret
funs ENDP

main PROC
push literal2
pop xbir

push literal3
pop ybir

mov eax, xbir
cmp eax, ybir
jb less
ja more
less:
	push xbir
	call writed
jmp flag
more:
	push ybir
	call writed
flag:
push xbir
push ybir
call fund
push eax
pop zbir

	push zbir
	call writed
push offset literal4
pop sabir

push sabir
push xbir
call funs
push eax
pop zbir

	push zbir
	call writed
push offset literal5
pop sbbir

	push sbbir
	call writes
	push offset literal6
	call writes
push 0
call ExitProcess
main ENDP
end main