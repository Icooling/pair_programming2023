#include <gtest/gtest.h>
#include <tchar.h>

#include "your_aim.h"

/// <summary>
/// ʹ��vs������3��/���Զ�������ע��
/// ��Ԫ���ԣ��������к�����ÿ����������дһ��������������֤�ú����ٷְٱ��⵽
/// </summary>
/// <param name="NameOfTestFunction">���Ժ�����</param>
/// <param name="DescriptionOfAssert">�����õ��Ĳ���Ч������</param>

TEST(NameOfTestFunction, DescriptionOfAssert)
{
	int res = your_aim_count();
	EXPECT_EQ(0, res);
}

/// <summary>
/// ���������޸�
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	testing::GTEST_FLAG(output) = "xml:";
	return RUN_ALL_TESTS();
}
