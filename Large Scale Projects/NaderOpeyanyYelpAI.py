import json 
import csv 
import pandas as pd 
 
outfile = open("review_stars.tsv", 'w') 
sfile = csv.writer(outfile, delimiter ="\t", quoting=csv.QUOTE_MINIMAL) 
sfile.writerow(['business_id','stars', 'text']) 
 
with open('yelp_academic_dataset_review.json', encoding="utf-8") as f: 
    for line in f: 
        row = json.loads(line) 
        # some special char must be encoded in 'utf-8' 
        sfile.writerow([row['business_id'], row['stars'], (row['text']).encode('utf-8')]) 
         
outfile.close() 
 
df= pd.read_csv('review_stars.tsv', delimiter ="\t", encoding="utf-8") 