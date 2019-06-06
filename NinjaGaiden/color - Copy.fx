sampler s0;
float timer;

float4 PixelShaderFunction(float2 coords: TEXCOORD0) : COLOR0
{
	float4 color = tex2D(s0, coords);
	float offset = 0;	
	if (changingMapTimer >= 0 && changingMapTimer < 500)
		offset = 0.2;
	else if (changingMapTimer >= 500 && changingMapTimer < 1000)
		offset = 0.4;
	else if (changingMapTimer >= 1000 && changingMapTimer < 1500)
		offset = 0.8;
	else if (changingMapTimer >= 1500 && changingMapTimer < 2000)
		offset = 1;
	else if (changingMapTimer >= 2000 && changingMapTimer < 2500)
		offset = 0.8;
	else if (changingMapTimer >= 2500 && changingMapTimer < 3000)
		offset = 0.4;
	else if (changingMapTimer >= 3000 && changingMapTimer < 3500)
		offset = 0.2;


	if (color.r - offset  > 0) color.r = color.r - offset ;
	else color.r = 0;
	if (color.g - offset  > 0) color.g = color.g - offset ;
	else color.g = 0;
	if (color.b - offset  > 0) color.b = color.b - offset ;
	else color.b = 0;
	return color;
}
float4 PixelShaderFunction1(float2 coords: TEXCOORD0) : COLOR0
{
	float4 color = tex2D(s0, coords);
	if (color.r - 0.2 > 0) color.r = color.r - 0.2;
	else color.r = 0;
	if (color.g - 0.2 > 0) color.g = color.g - 0.2;
	else color.g = 0;
	if (color.b - 0.2 > 0) color.b = color.b - 0.2;
	else color.b = 0;
	return color;
}
float4 PixelShaderFunction2(float2 coords: TEXCOORD0) : COLOR0
{
	
	float4 color = tex2D(s0, coords);
	if (color.r - 0.4 > 0) color.r = color.r - 0.4;
	else color.r = 0;
	if (color.g - 0.4 > 0) color.g = color.g - 0.4;
	else color.g = 0;
	if (color.b - 0.4 > 0) color.b = color.b - 0.4;
	else color.b = 0;
	return color;
}
float4 PixelShaderFunction3(float2 coords: TEXCOORD0) : COLOR0
{
	
	float4 color = tex2D(s0, coords);
	if (color.r - 0.8 > 0) color.r = color.r - 0.8;
	else color.r = 0;
	if (color.g - 0.8 > 0) color.g = color.g - 0.8;
	else color.g = 0;
	if (color.b - 0.8 > 0) color.b = color.b - 0.8;
	else color.b = 0;
	return color;
}
float4 PixelShaderFunction4(float2 coords: TEXCOORD0) : COLOR0
{
	
	float4 color = tex2D(s0, coords);
	if (color.r - 1 > 0) color.r = color.r - 1;
	else color.r = 0;
	if (color.g - 1 > 0) color.g = color.g - 1;
	else color.g = 0;
	if (color.b - 1 > 0) color.b = color.b - 1;
	else color.b = 0;
	return color;
}
technique Technique1
{
	pass Pass1
	{
		PixelShader = compile ps_2_0 PixelShaderFunction();
	}
	/*pass Pass2
	{
		PixelShader = compile ps_2_0 PixelShaderFunction2();
	}
	pass Pass3
	{
		PixelShader = compile ps_2_0 PixelShaderFunction3();
	}
	pass Pass4
	{
		PixelShader = compile ps_2_0 PixelShaderFunction4();
	}*/
}