#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

static void		ft_free_matrix(void **matrix, size_t size);
static size_t	ft_count_vectors(void **matrix);
static char		**ft_split(char const *s, char c);

char*	kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
	return (document[n - 1][m - 1][k - 1]);
}

char**	kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
	return (document[m - 1][k - 1]);
}

char***	kth_paragraph(char**** document, int k) {
	return (document[k - 1]);
}

char****	get_document(char* text)
{
	char		****document;
	char		**paragraphs;
	char		**sentences;
	int			paragraphs_num;
	int			sentences_num;
	int			paragraphs_counter;
	int			sentences_counter;

	paragraphs = ft_split(text, '\n');
	paragraphs_num = ft_count_vectors((void **)paragraphs);
	document = malloc(sizeof(char *) * (paragraphs_num + 1));
	document[paragraphs_num] = NULL;
	paragraphs_counter = -1;
	while (++paragraphs_counter < paragraphs_num)
	{
		sentences = ft_split(paragraphs[paragraphs_counter], '.');
		sentences_num = ft_count_vectors((void **)sentences);
		document[paragraphs_counter] = malloc(sizeof(char *) * (sentences_num + 1));
		document[paragraphs_counter][sentences_num] = NULL;
		sentences_counter = -1;
		while (++sentences_counter < sentences_num)
			document[paragraphs_counter][sentences_counter] = ft_split(\
				sentences[sentences_counter], ' ');
		ft_free_matrix((void **)sentences, sentences_num);
	}
	ft_free_matrix((void **)paragraphs, paragraphs_num);
	return (document);
}

static void	ft_free_matrix(void **matrix, size_t size)
{
	size_t	i;

	i = -1;
	if (matrix != NULL)
	{
		if (size)
		{
			while (++i < size)
				free(matrix[i]);
		}
		else
			while (matrix[++i])
				free(matrix[i]);
		free(matrix);
	}
}

static size_t	ft_count_vectors(void **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_len;
	char			*ptr;

	if (!s)
		return (NULL);
	s_len = strlen(s);
	if (start >= s_len)
		ptr = malloc(sizeof(char) * 1);
	else if (len > s_len - start)
		ptr = malloc(sizeof(char) * (s_len - start + 1));
	else
		ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && ((start + i) < s_len) && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	num_of_words(char const *s, char c)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		total++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (total);
}

static char	*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	i;
	size_t	words;

	if (s != NULL)
	{
		words = num_of_words(s, c);
		final = (char **)malloc(sizeof(char *) * (words + 1));
		if (!(final))
			return (NULL);
		i = 0;
		while (i < words)
		{
			s = next_word(s, c);
			final[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!final[i])
				return (NULL);
			i++;
			s += ft_wordlen(s, c);
		}
		final[words] = NULL;
		return (final);
	}
	return (NULL);
}

char*	get_input_text(void)
{
	int		paragraph_count;
	char	p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];

	scanf("%d", &paragraph_count);
	memset(doc, 0, sizeof(doc));
	getchar();
	for (int i = 0; i < paragraph_count; i++)
	{
		scanf("%[^\n]%*c", p[i]);
		strcat(doc, p[i]);
		if (i != paragraph_count - 1)
			strcat(doc, "\n");
	}

	char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
	strcpy(returnDoc, doc);
	return (returnDoc);
}

void	print_word(char* word) {
	printf("%s", word);
}

void	print_sentence(char** sentence)
{
	int		word_count;

	scanf("%d", &word_count);
	for (int i = 0; i < word_count; i++)
	{
		printf("%s", sentence[i]);
		if(i != word_count - 1)
			printf(" ");
	}
} 

void	print_paragraph(char*** paragraph)
{
	int sentence_count;
	scanf("%d", &sentence_count);
	for (int i = 0; i < sentence_count; i++) {
		print_sentence(*(paragraph + i));
		printf(".");
	}
}

int	main(void)
{
	char*		text = get_input_text();
	char****	document = get_document(text);
	int			q;


	scanf("%d", &q);
	while (q--)
	{
		int		type;

		scanf("%d", &type);
		if (type == 3)
		{
			int		k, m, n;
			scanf("%d %d %d", &k, &m, &n);
			char*	word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
			print_word(word);
		}
		else if (type == 2)
		{
			int		k, m;
			scanf("%d %d", &k, &m);
			char**	sentence = kth_sentence_in_mth_paragraph(document, k, m);
			print_sentence(sentence);
		}
		else
		{
			int		k;
			scanf("%d", &k);
			char***	paragraph = kth_paragraph(document, k);
			print_paragraph(paragraph);
		}
		printf("\n");
	}
}
