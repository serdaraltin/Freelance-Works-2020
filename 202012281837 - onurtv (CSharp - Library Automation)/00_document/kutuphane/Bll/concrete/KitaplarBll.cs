using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Bll.Abstract;
using Dal.Abstract;
using entities.Concrete;

namespace Bll.concrete
{
    public class KitaplarBll: IKitaplarBll
    {
        IKitaplarDal _Kitaplar;
        public KitaplarBll(IKitaplarDal Kitaplar)
        {
            _Kitaplar = Kitaplar;
        }
        public void Add(kitaplar kitaplar)
        {
            _Kitaplar.Add(kitaplar);
        }

        public void Delete(kitaplar kitaplar)
        {
            _Kitaplar.Delete(kitaplar);
        }

        public List<kitaplar> getAll()
        {
            return _Kitaplar.getAll(x=>x.durum==true);
        }

        public kitaplar getOneBarcodeId(string barkod)
        {
            return _Kitaplar.getOne(x => x.barkodNo == barkod);
        }

        public kitaplar getOneByDepositId(int id)
        {
            return _Kitaplar.getOne(x => x.emanettekiKitaplar.Any(y => y.id == id));
        }

        public kitaplar getOneById(int id)
        {
            return _Kitaplar.getOne(x => x.id == id);
        }

        public void Update(kitaplar kitaplar)
        {
            _Kitaplar.Update(kitaplar);
        }
    }
}
