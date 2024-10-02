from dotenv import load_dotenv
import os
import openai

load_dotenv()
openai.api_key = os.getenv('OPENAI_API_KEY')

# GPT 모델 호출 함수
def call_gpt():
    try:
        response = openai.ChatCompletion.create(
            model="gpt-4o",
            messages=[
                {"role": "system", "content": "You are a helpful assistant."},
                {"role": "user", "content": "버퍼 오버플로우 해결방안 1줄씩 3가지 알려줘"}
            ],
            n=1,
            stop=None,
            temperature=0.7,
        )

        response = response['choices'][0]['message']['content'].strip()
        result = response.split('\n')
        print(result)
        return result

    except Exception as e:
        return f"Error: {e}"