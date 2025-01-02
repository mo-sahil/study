from dotenv import load_dotenv
import os
import tweepy

load_dotenv()

bearer_token = os.getenv('TWITTER_BEARER_TOKEN')

client = tweepy.Client(bearer_token=bearer_token)

def build_test_set(search_keyword):
    try:
        tweets = client.search_recent_tweets(query=search_keyword, max_results=5)
        tweet_list = tweets.data if tweets.data else []
        
        print(f"Fetched {len(tweet_list)} tweets for the term '{search_keyword}'")
        return [{"text": tweet.text, "label": None} for tweet in tweet_list]
    except Exception as e:
        print(f"An error occurred: {e}")
        return None

search_term = input("Enter a search keyword: ")
test_data_set = build_test_set(search_term)

print(test_data_set)
