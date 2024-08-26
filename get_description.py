desc_dict = {
    0: "안전한 코드 입니다.",
    1: "메모리의 스택 영역에서 할당된 버퍼의 크기를 초과하는 데이터를 쓰는 경우 발생하는 보안 취약점입니다."
}

def get_description(ai):
    data = desc_dict[ai]
    return data