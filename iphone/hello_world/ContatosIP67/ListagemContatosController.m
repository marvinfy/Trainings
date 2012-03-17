//
//  ListagemContatosController.m
//  ContatosIP67
//
//  Created by ios2534 on 12/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ListagemContatosController.h"
#import "Contato.h"
#import "FormularioController.h"
#import "EditContatoController.h"


@implementation ListagemContatosController

@synthesize contatos;


- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    /*
    
    contatos = [[NSMutableArray alloc] initWithObjects:@"MV", @"Marcus Vinicius", @"Teste", nil];

     */
    /*
     [self title:@"Contatos"];
    */
    
    UIBarButtonItem *adicionar = [[UIBarButtonItem alloc] 
                                  initWithBarButtonSystemItem:UIBarButtonSystemItemAdd 
                                  target:self 
                                  action:@selector(mostraFormContato)
                                  ];
                                                                        
    self.navigationItem.rightBarButtonItem = adicionar;
    
    self.navigationItem.leftBarButtonItem = self.editButtonItem;
    
    UILongPressGestureRecognizer *longPress = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(exibeMaisAcoes:)];
                                               
    [self.tableView addGestureRecognizer:longPress];
}

-(void) exibeMaisAcoes: (UIGestureRecognizer *) gesture
{
    if (gesture.state == UIGestureRecognizerStateBegan)
    {
        CGPoint ponto = [gesture locationInView:self.tableView];
        NSIndexPath *index = [self.tableView indexPathForRowAtPoint:ponto];
        
        contatoSelecionado = [contatos objectAtIndex:index.row];
        
        UIActionSheet *opcoes = [[UIActionSheet alloc] 
                                 initWithTitle: contatoSelecionado.nome
                                 delegate:self 
                                 cancelButtonTitle:@"Cancelar"
                                 destructiveButtonTitle:nil
                                 otherButtonTitles:@"Ligar", @"Enviar Email", @"Visualizar site", @"Abrir Mapa", 
                                 nil];
        [opcoes showInView: self.view];
        
    }
}

- (void)abrirAplicativoComURL:(NSString *)url
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
}

- (void)tableView:
                    (UITableView *)tableView 
                    commitEditingStyle: (UITableViewCellEditingStyle) editingStyle 
                    forRowAtIndexPath:(NSIndexPath *)indexPath
{

    if (editingStyle == UITableViewCellEditingStyleDelete)
    {
        [contatos removeObjectAtIndex:indexPath.row];
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject: indexPath] withRowAnimation: UITableViewRowAnimationFade];
        /*[self.tableView reloadData];*/
    }
}


-(void) mostraFormContato
{
    FormularioController *formularioContatos = [[FormularioController alloc] initWithNibName:@"FormularioController" bundle:[NSBundle mainBundle]];
    UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:formularioContatos];

    formularioContatos.delegate = self;
    
    [self presentModalViewController:navigationController animated:YES];
}


-(void) contatoAdicionado: (Contato *) contato {
    [contatos addObject:contato];
    [self.tableView reloadData];
}

-(void) contatoAlterado {
    [self.tableView reloadData];
}


-(void)ligar
{
    UIDevice *device = [UIDevice currentDevice];
    if ([device.model isEqualToString:@"iPhone"])
    {
        NSString *numero = [NSString stringWithFormat:@"tel:%@", contatoSelecionado.telefone];
        [self abrirAplicativoComURL:numero];
    }
    else
    {
        [[[UIAlertView alloc] initWithTitle:@"Impossivel fazer ligacao"
                                    message:@"Seu dispositivo nao e um iPhone" 
                                   delegate:nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil] show];
    }
}

-(void)enviarEmail
{
    
    if ([MFMailComposeViewController canSendMail])
    {
        MFMailComposeViewController *enviadorEmail = [[MFMailComposeViewController alloc] init];
        
        enviadorEmail.mailComposeDelegate = self;
        [enviadorEmail setToRecipients:[NSArray arrayWithObject:contatoSelecionado.email]];
        [enviadorEmail setSubject:@"Caelum"];
        
        [self presentModalViewController:enviadorEmail animated:YES];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Ops"
                                                        message: @"Não é possível enviar e-mails!"
                                                       delegate: nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles: nil];
        [alert show];
    
    }
    
}

-(void)abrirSite
{
    NSString *url = contatoSelecionado.site;
    [self abrirAplicativoComURL:url];
}


-(void)mostrarMapa
{
    NSString *url = [[NSString stringWithFormat:
                      @"http://maps.google.com/maps?q=%@", contatoSelecionado.endereco]
                     stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    [self abrirAplicativoComURL:url];
}

-(void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    switch(buttonIndex)
    {
        case 0:
            [self ligar];
            break;
        case 1:
            [self enviarEmail];
            break;
        case 2:
            [self abrirSite];
            break;
        case 3:
            [self mostrarMapa];
            break;
        default:
            break;
    }
    
    contatoSelecionado = nil;
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

-(void)mailComposeController:(MFMailComposeViewController *)controller 
         didFinishWithResult:(MFMailComposeResult)result error:(NSError *)error
{
    [self dismissModalViewControllerAnimated:YES];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - Table view data source


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return [contatos count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier];
    }
    
    // Configure the cell...
    
    Contato *c = [contatos objectAtIndex:indexPath.row];
    
    cell.textLabel.text = c.nome;
    cell.detailTextLabel.text = c.email;
    
    return cell;
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/


// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
    Contato *c = [contatos objectAtIndex:fromIndexPath.row];
    [contatos removeObjectAtIndex: fromIndexPath.row];
    [contatos insertObject: c atIndex:toIndexPath.row];

}



// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}


#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    Contato *c = [contatos objectAtIndex:indexPath.row];
    
    EditContatoController *editarContato = [[EditContatoController alloc]initWithContato:c];
    
    editarContato.delegate = self;
    
    [self.navigationController pushViewController:editarContato animated:YES];
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    
    
    // Navigation logic may go here. Create and push another view controller.
    /*
     <#DetailViewController#> *detailViewController = [[<#DetailViewController#> alloc] initWithNibName:@"<#Nib name#>" bundle:nil];
     // ...
     // Pass the selected object to the new view controller.
     [self.navigationController pushViewController:detailViewController animated:YES];
     */
}
                    

@end
