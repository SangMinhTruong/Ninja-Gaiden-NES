sampler s0;

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
		PixelShader = compile ps_2_0 PixelShaderFunction1();
	}
	pass Pass2
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
	}
}