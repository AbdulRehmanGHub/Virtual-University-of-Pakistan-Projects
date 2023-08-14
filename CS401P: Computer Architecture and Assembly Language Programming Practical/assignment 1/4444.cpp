[org 0x0100]
jmp start

num: db 4
sum: db 0

start:
mov bx,[num]
mov cx,4
mov ax,0

label:
and bx,1
cmp bx,0
jnz skip
add ax,cx

skip:
sub cx,1
mov bx,cx
cmp cx,0
jnz label

mov [sum],ax
mov ax,0x4c00
int 0x21
