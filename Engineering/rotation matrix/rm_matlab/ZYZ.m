function outM = ZYZ( a1, a2, a3 )
%order: rotation angle about z,y,z in radian
%output: rotation matrix
outM = [cos(a1) -sin(a1) 0; sin(a1) cos(a1) 0; 0 0 1] * [cos(a2) 0 sin(a2);0 1 0;-sin(a2) 0 cos(a2)] * [cos(a3) -sin(a3) 0; sin(a3) cos(a3) 0; 0 0 1];

end

