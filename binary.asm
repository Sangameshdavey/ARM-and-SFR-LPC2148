	area ca,code,readonly
start 
	ldr r0,=0x40000000;
	ldr r3,[r0];
	mov r1,#0;
loop 
	ldr r2,[r0,#4]!;
	cmp r2,r1;
	BLT goto
	mov r1,r2;
goto 
	subs r3,r3,#1;
	BNE loop;
	str r1,[r0,#8]
l  B l;
	end;