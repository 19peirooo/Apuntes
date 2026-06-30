import sys
import logging
import pymysql
import json

rds_host = "3.227.158.163"

username = "admin"
password ="password"
dbname = "calculator"

def suma(a, b):
    return a + b
   
def resta(a, b):
    return a - b
   
def default():
    return "Opcion Invalida"
   
def switch(case, a, b):
    sw = {
        "+": suma(a, b),
        "-": resta(a, b),
        
    }
    return sw.get(case, default())



def lambda_handler(event , context):
    op1=float(event["queryStringParameters"]["op1"]);
    op2=float(event["queryStringParameters"]["op2"]);
    op=event["queryStringParameters"]["op"];
    #result=float(op1)+float(op2);
    result=0;
    result=switch(op, op1, op2);
    redirectPage="";    
    print(op1);
    print(op2);
    print(op);
    
  
    
    try:
        conn = pymysql.connect(rds_host, user=username, passwd=password, db=dbname, connect_timeout=10, port=3306)
        with conn.cursor() as cur:
            #cur.execute("create table tableRDS2 ( name varchar(20) NOT NULL ,  lastname varchar(20) NOT NULL )")
            #cur.execute(event["queryStringParameters"]["query"])
            cur.execute("insert into resultados values (" + str(op1)+","+str(op2)+",'" +op+ "'," + str(result)+ ")");
            conn.commit();
            #cur.execute("insert into prueba values ('" + event['key1'] + "','" +event['key2']+"')")
            conn.commit();
            cur.execute("select pagename from webpages where type='success' ");
            #for row in cur:
            #    print(row[0])
            redirectPage=cur.fetchone()[0];
            cur.close();
    except pymysql.MySQLError as e:    
        print (e)
    conn.close();
    return {
        'statusCode': 200,
        'headers': { 'Access-Control-Allow-Origin' : '*' },
        'body' : json.dumps( { 'res': str(result), 'redirect': redirectPage} )
    }
#      

