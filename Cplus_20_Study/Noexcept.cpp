//�@noexcept
//�@C++11�œ������ꂽ�B
//�@throw�L�[���[�h�̗�O�d�l�̑��
//�@�֐����ǂ̗�O�𑗏o����\�������邩�񋓂���̂ł͂Ȃ�
//�@��O�̉\���̂��邩�Ȃ������w�肷��
//�@��O�𑗏o����\��������֐��Fnoexcept(false)
//�@��O�𑗏o����\�����Ȃ��֐��Fnoexcept(true) or noexcept
//�@https://cpprefjp.github.io/lang/cpp11/noexcept.html


class Player
{
	float hp = 0.0f;
public:
	//��O���o���Ȃ�
	float getHP() const noexcept
	{
		return hp;
	}

};