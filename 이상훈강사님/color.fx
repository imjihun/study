//***************************************************************************************
// color.fx by Frank Luna (C) 2011 All Rights Reserved.
//
// Transforms and colors geometry.
//***************************************************************************************

cbuffer cbPerObject
{
	/*
	일명 동차 좌표계라고 불리는 4 by 4 행렬을 사용할 때 float4x4 를 사용한다.
	동차 좌표계의 핵심은 물체의 평행 이동, 회전, 사이즈 조절을
	단순히 4 by 4 행렬 곱셈 한 번으로 끝내버릴 수 있다는 것이다.
	**********************************************************************/
	float4x4 gWorldViewProj; 
};

struct VertexIn
{
	float3 PosL  : POSITION;
    float4 Color : COLOR;
};

struct VertexOut
{
	float4 PosH  : SV_POSITION;
    float4 Color : COLOR;
};

VertexOut VS(VertexIn vin)
{
	VertexOut vout;
	
	// Transform to homogeneous clip space.
	vout.PosH = mul(float4(vin.PosL, 1.0f), gWorldViewProj);
	
	// Just pass vertex color into the pixel shader.
    vout.Color = vin.Color;
    
    return vout;
}

float4 PS(VertexOut pin) : SV_Target
{
    return pin.Color;
}

technique11 ColorTech
{
/*
이게 뭔 뜻이냐 ?
앞서서 우리가 봐왔던 그래픽 파이프라인이란 것들이 있었다.
굉장히 복잡하게 Input Assembler, Vertex Shader, Pixel Shader,
Tessellation Shader, Domain Shader, Computation Shader 등등
여러가지가 많이 있는데 지금 보면
technique 로 시작해서 pass 부분에서 Entry Point 가 지정되어 있고
이 안에서 쓰이는 코드들은 위쪽에 모두 정의 되어있다.
즉, 우리가 그래픽 파이프라인 자체를
프로그래밍 해서 조작할 수 있음을 의미한다.
[ 이러한 것들을 Programmable Device 라고 한다 ]
***********************************************************/
    pass P0
    {
        SetVertexShader( CompileShader( vs_5_0, VS() ) );
		SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_5_0, PS() ) );
    }
}
