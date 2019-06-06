sampler s0;
float timer;
int gameOverColor;

float4 ChangeMapFunction(float2 coords: TEXCOORD0) : COLOR0
{
	float4 color = tex2D(s0, coords);
	float offset = 0;
	if (timer >= 0 && timer < 500)
		offset = 0.2;
	else if (timer >= 500 && timer < 1000)
		offset = 0.4;
	else if (timer >= 1000 && timer < 1500)
		offset = 0.8;
	else if (timer >= 1500 && timer < 2000)
		offset = 1;
	else if (timer >= 2000 && timer < 2500)
		offset = 0.8;
	else if (timer >= 2500 && timer < 3000)
		offset = 0.4;
	else if (timer >= 3000 && timer < 3500)
		offset = 0.2;


	if (color.r - offset  > 0) color.r = color.r - offset ;
	else color.r = 0;
	if (color.g - offset  > 0) color.g = color.g - offset ;
	else color.g = 0;
	if (color.b - offset  > 0) color.b = color.b - offset ;
	else color.b = 0;
	return color;
}

float4 GameOverFunction(float2 coords: TEXCOORD0) : COLOR0
{
	float4 color = tex2D(s0, coords);
	int red = (int)(color.r * 255);
	int blue = (int)(color.b * 255);
	int green = (int)(color.g * 255);
	if (red  == 0 &&
	    green  >= 220 &&
	    (blue  >= 200 && blue  <= 230))
	{
		color.rgb = 0;
	}
	else
	{
		if (gameOverColor == 1)
			color.rgb = color.grb;
		if (gameOverColor == 2)
			color.rgb = color.bgr;
		if (gameOverColor == 3)
			color.rgb = color.rbg;
		if (gameOverColor == 4)
			color.rgb = color.gbr;
		if (gameOverColor == 5)
			color.rgb = color.brg;
		if (gameOverColor == 6)
			color.rgb = 1 - color.brg;
		if (gameOverColor == 7)
			color.rgb = 1 - color.rgb;
		if (gameOverColor == 8)
			color.rgb = 1 - color.gbr;

	}
	return color;
}

technique Technique1
{
	pass Pass1
	{
		PixelShader = compile ps_2_0 ChangeMapFunction();
	}
	pass Pass2
	{
		PixelShader = compile ps_2_0 GameOverFunction();
	}
}
