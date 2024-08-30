import openai
def OpenAi(payload):
    # OpenAI API 설정
    openai.api_key = '' #key

    model = "gpt-3.5-turbo"

    # 질문 작성하기
    query = f"{payload} 취약점 대응방법 3가지알려줘"

    messages = [
    {
        "role": "system",
        "content": "You are a helpful assistant who is good at detailing."
    },
    {
        "role": "user",
        "content": query
    }
    ]

    #  ChatGPT API 호출하기 함수 돌아갈 떄 feach로
    response = openai.ChatCompletion.create(
        model=model,
        messages=messages
    )
    answer = response['choices'][0]['message']['content']
    return answer