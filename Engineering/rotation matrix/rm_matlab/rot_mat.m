function outM = rot_mat( u, phi )
%input: 
%output: rotation matrix 
uhat = [0 -u(3) u(2);u(3) 0 -u(1);-u(2) u(1) 0];
outM = eye(3) * cos(phi) + u * u' * (1 - cos(phi)) + uhat * sin(phi);

end

