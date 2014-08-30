// Debugging snippets:

// Highlight 'out of texture' regions
if ((coord.x < 0) 
	|| (coord.x > 1) 
	|| (coord.y < 0) 
	|| (coord.y > 1))
    FragColor += vec4(1,0,0,.5);//coord = vec2(0);
if ((offset.x == 0) && (coord.x > 0.5))
    FragColor += vec4(0,1,0,.5);//coord = vec2(0);
if ((offset.x != 0) && (coord.x < 0.5))
    FragColor += vec4(0,0,1,.5);//coord = vec2(0);

// Highlight the 'viewport_position' midpoint
if (viewport_position.x > 0) 
	FragColor = vec4(1, 0, 0, 0.5);

// Highlight the 'relative_position' midpoint (x, y)
if(relative_pos.x > 0 ) FragColor = vec4(1,0,0,1);
if(relative_pos.y > 0 ) FragColor = vec4(0,1,0,1);

// Check that the spherical deform is round-ish
if (r > 0.3) FragColor = vec4(0,0,1,1);