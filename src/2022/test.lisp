(define my-language 'English)

(define translations
  #hash([Chinese . "你好 世界"]
        [English . "Hello world"]
        [French . "Bonjour le monde"]
        [German . "Hallo Welt"]
        [Greek . "Γειά σου, κόσμε"]
        [Portuguese . "Olá mundo"]
        [Spanish . "Hola mundo"]
        [Thai . "สวัสดีชาวโลก"]
        [Turkish . "Merhaba Dünya"]))

(define my-hello-world
  (hash-ref translations my-language
            "hello world"))

(message-box "" my-hello-world)
