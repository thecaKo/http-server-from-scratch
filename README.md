# Servidor HTTP em C

Este projeto implementa um servidor _HTTP_ simples em C, que escuta conexões na porta 3490 e responde com uma página HTML básica.

Antes de executar o servidor, você precisa ter o seguinte instalado em seu sistema:
```
GCC (GNU Compiler Collection)
Bibliotecas padrão de rede do Linux (como arpa/inet.h, netdb.h, etc.)
```
Esses pacotes geralmente estão disponíveis em distribuições Linux como parte do build-essential e outras ferramentas de desenvolvimento.

### Compilação

Para compilar o servidor _HTTP_, siga os passos abaixo:
```
Clone o repositório e compile usando | gcc server.c -o server.
```
### Execução

Para iniciar o servidor HTTP:
```
./server.c
```
O servidor irá iniciar e escutar na porta 3490. Após o servidor ser iniciado, ele vai exibir a mensagem:
```
Servidor escutando na porta 3490...
```
### Testando a conexão 

Você pode testar a resposta do servidor _HTTP_ acessando `http://localhost:3490` utilizando um navegador ou o `telnet`, `curl`, enfim...

Você deve ver a seguinte resposta HTML:
```
Server HTTP with C
```

### Parando o servidor

Para parar o servidor, simplesmente pressione `CTRL+C`.

### Como funciona pode de baixo dos panos?

Muito obrigado ao Beej por esse guia incrível: https://beej.us/guide/bgnet/html/split-wide/index.html

#### Função `main()`

A função principal configura e executa o servidor:

`sockfd`: Descritor do _socket_ do servidor.

`new_fd`: Descritor para nova conexão.

`bindcall, listencall`: Verificações das chamadas bind() e listen().

`status, hints, servinfo`: Usados para resolver o endereço e configurar o _socket_.

`buffer`: Armazena dados recebidos.

#### Configuração de `getaddrinfo()`

`struct addrinfo`: Criando a estrutura que vai ser alimentada depois.
`getaddrinfo()`: Busca o IPV4(ou IPV6), no caso o do `localhost``.

#### Criação e Configuração do `Socket`

`socket()`: Cria um _socket_ e retorna um socker descriptor.

Os _sockets_ sao uma forma de comunicação entre programas permitindo a troca de dados por meio de um descritor de arquivos no UNIX.

Um problema que encontrei no desenvolvimento foi o _Adress_ que estava sendo ocupado pelo _socket_ anterior, mesmo após o término da execução.
Utilizando `SO_REUSEADDR` que é configurada com `setsockopt()` resolveu o problema.

#### Bind e Escutando Conexões

`bind()`: Associa um _socket_ a um endereco IP e porta especificos. E e isso.


#### Escutando X porta

`listen()`: Usado para deixar o servidor _pronto_ para aceitar conexões, em uma porta especifica.

#### Aceitação e Processamento de Conexões

`accept()`: aceita a conexao e recebe dados com `recv()`. Ao aceitar uma conexao, um novo _socket_ e aberto, unicamente para essa comunicação, deixando o outro livre para as próximas conexões.


#### Envio de Resposta HTTP

Configurei uma resposta _HTTP_ simples que sera retornada ao acessar a url _http://localhost:3490_




